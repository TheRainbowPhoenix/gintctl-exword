from pathlib import Path
import struct
import sys

from PIL import Image

sys.path.insert(0, sys.argv[1])

import fxconv

image = Image.open(sys.argv[2]).convert("RGBA")
profile = fxconv.CgProfile.find("p8_rgb565")
data, stride, palette, colors = fxconv.image_encode(image, profile)

if image.size != (96, 56) or stride != 96 or colors != 256:
    raise ValueError("Unexpected train image dimensions or palette")

header = b"GCT1" + struct.pack(">HH", image.width, image.height)

Path(sys.argv[3]).write_bytes(header + palette + data)
