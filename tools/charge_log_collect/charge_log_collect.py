import struct
import urllib.request
import matplotlib.pyplot as plt
import datetime

WARP_CHARGER = [
    'wallbox-cp1',
    'wallbox-cp2',
    'wallbox-cp3',
    'wallbox-cp4',
    'wallbox-cp5',
    'wallbox-cp6',
    'wallbox-cp7',
    'wallbox-cp8',
    'wallbox-hr1',
    'wallbox-hr2',
    'wallbox-hr3',
    'wallbox-hr4',
    'wallbox-hr5',
    'wallbox-hr6'
]

def plot_charge_log_bar(charge_logs):
    monthly_data = {}
    for charge_log in charge_logs:
        if charge_log['timestamp'] == 0:
            continue
        date = datetime.datetime.fromtimestamp(charge_log['timestamp']*60)
        month = date.strftime('%Y-%m')
        diff = charge_log['kwh_end'] - charge_log['kwh_start']
        url = charge_log['url']
        if month not in monthly_data:
            monthly_data[month] = {}
        if url not in monthly_data[month]:
            monthly_data[month][url] = 0
        monthly_data[month][url] += diff

    months = sorted(monthly_data.keys())
    dates = [datetime.datetime.strptime(month, '%Y-%m') for month in months]
    num_months = len(months)
    num_chargers = len(WARP_CHARGER)
    bar_width = 0.8 / num_chargers

    fig, ax = plt.subplots(figsize=(15, 8))
    colors = plt.cm.get_cmap('tab20', num_chargers)

    for idx, url in enumerate(WARP_CHARGER):
        kwh = [monthly_data[month].get(url, 0) for month in months]
        bar_positions = [i + idx * bar_width for i in range(num_months)]
        ax.bar(bar_positions, kwh, bar_width, label=url, color=colors(idx))

    ax.set_title('Monthly Charge Log')
    ax.set_xlabel('Month')
    ax.set_ylabel('kWh')
    ax.set_xticks([i + bar_width * (num_chargers / 2) for i in range(num_months)])
    ax.set_xticklabels([month.strftime('%Y-%m') for month in dates])
    ax.legend()

    plt.tight_layout()
    plt.show()

def plot_charge_log(charge_logs):
    timestamps = []
    kwh_sum = []
    kwh = []
    last_kwh = 0
    for charge_log in charge_logs:
        if charge_log['timestamp'] == 0:
            continue
        timestamps.append(charge_log['timestamp']*60)
        diff = charge_log['kwh_end'] - charge_log['kwh_start']
        last_kwh += diff
        kwh.append(diff)
        kwh_sum.append(last_kwh)

    dates = [datetime.datetime.fromtimestamp(ts) for ts in timestamps]
    plt.plot(dates, kwh_sum, label='kWh')
    plt.xlabel('timestamp')
    plt.ylabel('kWh')
    plt.legend()
    plt.show()


def get_charge_log(url):
    # get charge log via http HTTP API from http://$URL/charge_tracker/charge_log
    charge_log_binary = urllib.request.urlopen("http://" + url + "/charge_tracker/charge_log")

    # Charge log binary format:
    # offset      timestamp kwh_start id duration kwh_end
    # 0x00000000: c2eb b301 3bf8 8c45 00 57 6b00  f236 8e45
    # 0x00000010: f4fc b301 2738 8e45 00 ae 9300  a846 8f45
    # 0x00000020: 2c02 b401 df46 8f45 00 0b 6d00  be58 9045
    charge_log = []
    while True:
        data = charge_log_binary.read(16)
        if not data:
            break
        timestamp, kwh_start, id, d0, d1, d2, kwh_end = struct.unpack('<IfBBBBf', data)
        duration =  (d2 << 16) | (d1 << 8) | d0

        # This assumes that the timestamp is unique
        charge_log.append({
            'timestamp': timestamp,
            'kwh_start': kwh_start,
            'id': id,
            'duration': duration,
            'kwh_end': kwh_end,
            'url': url
        })

    return charge_log

if __name__ == '__main__':
    charge_logs = []
    for charger in WARP_CHARGER:
        charge_logs.extend(get_charge_log(charger))

    charge_logs = sorted(charge_logs, key=lambda x: x['timestamp'])

    plot_charge_log(charge_logs)
    # plot_charge_log_bar(charge_logs)