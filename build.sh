WIFI_SSID="your_ssid"
WIFI_PASSWORD="your_p4sw0rd"
PICO_BOARD="pico_w"

rm -Rf ./build
mkdir build
cd build
cmake -DPICO_BOARD=${PICO_BOARD} -DWIFI_SSID=${WIFI_SSID} -DWIFI_PASSWORD={WIFI_PASSWORD} ../pshell -G Ninja
ninja
cd ..
picotool info ./build/pshell_exec.uf2 -a