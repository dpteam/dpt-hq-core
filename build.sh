#!/bin/sh

set +v
echo "Compressing. Please wait... [Approximately 2-5 mins]"
cd pk3_data
..\7z a -t7z -m0=lzma2 -mx=9 -aoa "..\DPT-HQ-Core-current.pk7" *
clear
echo "Compression complete."
sleep
