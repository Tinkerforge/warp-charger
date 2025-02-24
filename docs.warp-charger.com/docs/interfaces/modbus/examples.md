---
sidebar_position: 2
---

# Beispiele

Im weiteren gibt es Beispiele für den Zugriff auf WARP Charger über Modbus/TCP.

## Python

```py
#!/usr/bin/env python3

from pymodbus.client    import ModbusTcpClient
from pymodbus.constants import Endian
from pymodbus.payload   import BinaryPayloadDecoder

# Register for power in Watt
REGISTER_POWER = 2002

# Create client object and connect to it
client = ModbusTcpClient('wallbox-2.localdomain')  
client.connect()

# Read input register REGISTER_POWER (2002) and convert it to float
result = client.read_input_registers(REGISTER_POWER, 2)
decoder = BinaryPayloadDecoder.fromRegisters(result.registers, byteorder=Endian.BIG)
power = decoder.decode_32bit_float()

# Close modbus connection
client.close()

# Print power
print('Aktuelle Leistung: {0}W'.format(power))
```

## Homematic

TODO