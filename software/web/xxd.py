import sys

with open(sys.argv[1], "rb") as f:
    with open(sys.argv[2], "w") as h:
        h.write("const char {}[] = {{\n".format(sys.argv[3]))
        w = 0
        b = f.read(12)

        while len(b) != 0:
            # read first to prevent trailing , after last byte
            next_b = f.read(12)
            h.write("    " + ", ".join(["0x{:02x}".format(x) for x in b]) + (",\n" if len(next_b) != 0 else "\n"))
            w += len(b)
            b = next_b

        h.write("};\n")
        h.write("unsigned int {}_len = {};\n".format(sys.argv[3], w))
