cd ..
docker-command-line-interface pagexml-build:16.04 -- bash -c 'cp -p /opt/pagexml/py-pagexml/dist/*.egg .' &&
docker-command-line-interface pagexml-build:18.04 -- bash -c 'cp -p /opt/pagexml/py-pagexml/dist/*.egg .' &&
docker build --build-arg UBUNTU_TAG=16.04 --build-arg GDAL_VERSION=1i --build-arg CV_VERSION=2.4v5 -t pagexml-runtime:18.04 -f docker/Dockerfile_runtime . &&
docker build --build-arg UBUNTU_TAG=18.04 --build-arg GDAL_VERSION=20 --build-arg CV_VERSION=3.2 -t pagexml-runtime:18.04 -f docker/Dockerfile_runtime .
