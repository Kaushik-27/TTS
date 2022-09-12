#! /bin/bash
export LD_LIBRARY_PATH=.
sudo cp -rf RHVoice /usr/local/share/
./RHVoice-test -p evgeniy-eng -i a.txt -o b.mp3
