#!/usr/bin/python3 -u
from urllib.request import urlopen, URLError, Request

import json
import time
import argparse
import sys
import datetime

header = "Zeit (s),erlaubter Strom (A),L1 Spannung gegen Neutral (V),L2 Spannung gegen Neutral (V),L3 Spannung gegen Neutral (V),L1 Strom (A),L2 Strom (A),L3 Strom (A),L1 Wirkleistung (W),L2 Wirkleistung (W),L3 Wirkleistung (W),L1 Scheinleistung (VA),L2 Scheinleistung (VA),L3 Scheinleistung (VA),L1 Blindleistung (var),L2 Blindleistung (var),L3 Blindleistung (var),L1 Leistungsfaktor; Das Vorzeichen des Leistungsfaktors gibt die Richtung des Stromflusses an.,L2 Leistungsfaktor; Das Vorzeichen des Leistungsfaktors gibt die Richtung des Stromflusses an.,L3 Leistungsfaktor; Das Vorzeichen des Leistungsfaktors gibt die Richtung des Stromflusses an.,L1 relative Phasenverschiebung (°),L2 relative Phasenverschiebung (°),L3 relative Phasenverschiebung (°),Durchschnittliche Spannung gegen Neutral (V),Durchschnittlicher Strom (A),Summe der Phasenströme (A),Gesamtwirkleistung (W),Gesamtscheinleistung (VA),Gesamtblindleistung (var),Gesamtleistungsfaktor,Gesamtphasenverschiebung (°),Frequenz der Versorgungsspannung (Hz),Wirkenergie (Import; vom Fahrzeug aufgenommen) (kWh),Wirkenergie (Export; vom Fahrzeug abgegeben) (kWh),Blindenergie (Import; vom Fahrzeug aufgenommen) (kvarh),Blindenergie (Export; vom Fahrzeug abgegeben) (kvarh),Gesamtscheinenergie (kVAh),Transportierte elektrische Ladung (Ah),Bezogene Wirkleistung; Entspricht Import-Export-Differenz (W),Max. bezogene Wirkleistung; Höchster gemessener Wert (W),Bezogene Scheinleistung; Entspricht Import-Export-Differenz (VA),Max. bezogene Scheinleistung; Höchster gemessener Wert (VA),Bezogener Neutralleiterstrom (A),Max. bezogener Neutralleiterstrom; Höchster gemessener Wert (A),Spannung L1 zu L2 (V),Spannung L2 zu L3 (V),Spannung L3 zu L1 (V),Durchschnittliche Spannung zwischen Phasen (V),Neutralleiterstrom (A),L1 Total Harmonic Distortion (THD) der Spannung (%),L2 Total Harmonic Distortion (THD) der Spannung (%),L3 Total Harmonic Distortion (THD) der Spannung (%),L1 Total Harmonic Distortion (THD) des Stroms (%),L2 Total Harmonic Distortion (THD) des Stroms (%),L3 Total Harmonic Distortion (THD) des Stroms (%),Durchschnittliche Spannungs-THD (%),Durchschnittliche Strom-THD (%),L1 Bezogener Strom (A),L2 Bezogener Strom (A),L3 Bezogener Strom (A),L1 Max. bezogener Strom; Höchster gemessener Wert (A),L2 Max. bezogener Strom; Höchster gemessener Wert (A),L3 Max. bezogener Strom; Höchster gemessener Wert (A),Spannungs-THD L1 zu L2 (%),Spannungs-THD L2 zu L3 (%),Spannungs-THD L3 zu L1 (%),Durchschnittliche Spannungs-THD zwischen Phasen (%),Summe der Gesamtwirkenergien; Import-Export-Summe aller Phasen (kWh),Summe der Gesamtblindenergien; Import-Export-Summe aller Phasen (kvarh),L1 Wirkenergie (Import; vom Fahrzeug aufgenommen) (kWh),L2 Wirkenergie (Import; vom Fahrzeug aufgenommen) (kWh),L3 Wirkenergie (Import; vom Fahrzeug aufgenommen) (kWh),L1 Wirkenergie (Export; vom Fahrzeug abgegeben) (kWh),L2 Wirkenergie (Export; vom Fahrzeug abgegeben) (kWh),L3 Wirkenergie (Export; vom Fahrzeug abgegeben) (kWh),L1 Gesamtwirkenergie; Import-Export-Summe (kWh),L2 Gesamtwirkenergie; Import-Export-Summe (kWh),L3 Gesamtwirkenergie; Import-Export-Summe (kWh),L1 Blindenergie (Import; vom Fahrzeug aufgenommen) (kvarh),L2 Blindenergie (Import; vom Fahrzeug aufgenommen) (kvarh),L3 Blindenergie (Import; vom Fahrzeug aufgenommen) (kvarh),L1 Blindenergie (Export; vom Fahrzeug abgegeben) (kvarh),L2 Blindenergie (Export; vom Fahrzeug abgegeben) (kvarh),L3 Blindenergie (Export; vom Fahrzeug abgegeben) (kvarh),L1 Gesamtblindenergie; Import-Export-Summe (kvarh),L2 Gesamtblindenergie; Import-Export-Summe (kvarh),L3 Gesamtblindenergie; Import-Export-Summe (kvarh)"

def set_current(current, host):
    for i in range(3):
        try:
            req = Request(f"http://{host}/evse/external_current_update",
                        data=str(current).encode('utf-8'),
                        method='PUT',
                        headers={"Content-Type": "application/json"})
            with urlopen(req) as resp:
                resp.read()
            return True
        except:
            pass
    return False

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-c', '--current', type=int, default=32000)
    parser.add_argument('-s', '--step',  type=int, default=100)
    parser.add_argument('-d', '--delay',  type=int, default=10)
    parser.add_argument('host')

    args = parser.parse_args()

    host = args.host
    current = args.current
    step = args.step
    start = time.time()
    end = start + (args.current - 6000) / args.step * args.delay

    value_count = 0
    with open("current_ramp.csv", "w") as f:
        f.write(header + "\n")
        while current >= 6000:
            end = time.time() + (current - 6000) / args.step * args.delay

            if not set_current(current, host):
                return -1
            print(f"\r{current / 1000.0:.3f}A ~{datetime.timedelta(seconds=int(end - time.time()))}\033[K", end="")

            for i in range(args.delay):
                time.sleep(1)
                try:
                    with urlopen(f'http://{host}/meter/all_values') as resp:
                        response = resp.read()
                    values = json.loads(response)
                    value_count = len(values)
                    f.write(f"{time.time() - start:.3f},{current},{','.join([str(x) for x in values])}\n")
                except URLError:
                    f.write(f"{time.time() - start:.3f}{',' * (value_count + 1)}\n")
                print(f"\r{current / 1000.0:.3f}A ~{datetime.timedelta(seconds=int(end - time.time()))} {'.' * (i + 1)}", end="")
            current -= step
        print()
    return 0

if __name__ == "__main__":
    sys.exit(main())
