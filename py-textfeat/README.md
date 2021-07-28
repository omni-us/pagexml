To build wheel file:

docker run --rm -it -v /home:/home mauvilsa/pagexml:build-ubuntu20.04-py38 bash
apt-get update
apt-get install libmagick++-dev
cd /home/user/path/to/repo/pagexml/py-textfeat
./setup.py bdist_wheel
