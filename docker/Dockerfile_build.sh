cd ..
docker build --build-arg UBUNTU_TAG=16.04 -t pagexml-build:16.04 -f docker/Dockerfile_build . &&
docker build --build-arg UBUNTU_TAG=18.04 -t pagexml-build:18.04 -f docker/Dockerfile_build .
