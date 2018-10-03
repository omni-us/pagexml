cd ../../
docker-command-line-interface -- pagexml-build:16.04-py27 bash -c 'cp -p /opt/pagexml/py-pagexml/dist/*.egg .' &&
docker-command-line-interface -- pagexml-build:16.04-py35 bash -c 'cp -p /opt/pagexml/py-pagexml/dist/*.egg .' &&
docker-command-line-interface -- pagexml-build:18.04-py36 bash -c 'cp -p /opt/pagexml/py-pagexml/dist/*.egg .' &&
docker build -f docker/Dockerfile_runtime -t pagexml-runtime:16.04-py27 --build-arg UBUNTU_TAG=16.04 --build-arg GDAL_VERSION=1i --build-arg CV_VERSION=2.4v5 --build-arg PYTHON_VERSION= . &&
docker build -f docker/Dockerfile_runtime -t pagexml-runtime:16.04-py35 --build-arg UBUNTU_TAG=16.04 --build-arg GDAL_VERSION=1i --build-arg CV_VERSION=2.4v5 --build-arg PYTHON_VERSION=3 . &&
docker build -f docker/Dockerfile_runtime -t pagexml-runtime:16.04-py36 --build-arg UBUNTU_TAG=18.04 --build-arg GDAL_VERSION=20 --build-arg CV_VERSION=3.2  --build-arg PYTHON_VERSION=3 .
