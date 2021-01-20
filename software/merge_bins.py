import sys

args = sys.argv[1:]
if len(args) % 2 != 1:
    print("Usage: {} [OFFSET] [PATH] [OFFSET] [PATH] ... [TARGET]".format(sys.argv[0]))
    sys.exit(0)

target_path = args[-1]

offset_map = [(int(args[2*i], base=0), args[2*i+1]) for i in range(0, len(args) // 2)]

current_offset = offset_map[0][0]

with open(target_path, "wb") as target:
    for offset, source_path in offset_map:
        print("Padding with {} 0xFF bytes.".format(offset - current_offset))
        target.write(b"\xff" * (offset - current_offset))
        current_offset = offset
        print("Appending {}".format(source_path))
        with open(source_path, "rb") as source:
            data = source.read()
            current_offset += len(data)
            target.write(data)
