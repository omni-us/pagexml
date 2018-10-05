cd ../../
docker build -f py-pagexml/docker/Dockerfile_build -t pagexml-build:16.04-py27 --build-arg UBUNTU_TAG=16.04 --build-arg PYTHON_VERSION= . &&
docker build -f py-pagexml/docker/Dockerfile_build -t pagexml-build:16.04-py35 --build-arg UBUNTU_TAG=16.04 --build-arg PYTHON_VERSION=3 . &&
docker build -f py-pagexml/docker/Dockerfile_build -t pagexml-build:18.04-py36 --build-arg UBUNTU_TAG=18.04 --build-arg PYTHON_VERSION=3 .
