PAGEXML_VERSION=2019.10.10

#docker build \
#  -f Dockerfile_runtime \
#  -t mauvilsa/pagexml:runtime-ubuntu16.04-py27 \
#  --build-arg UBUNTU_TAG=16.04 \
#  --build-arg PYTHON_VERSION=2 \
#  --build-arg PAGEXML_VERSION=$PAGEXML_VERSION .

docker build \
  -f Dockerfile_runtime \
  -t mauvilsa/pagexml:runtime-ubuntu16.04-py35 \
  --build-arg UBUNTU_TAG=16.04 \
  --build-arg PYTHON_VERSION=3 \
  --build-arg PAGEXML_VERSION=$PAGEXML_VERSION .

docker build \
  -f Dockerfile_runtime \
  -t mauvilsa/pagexml:runtime-ubuntu18.04-py36 \
  --build-arg UBUNTU_TAG=18.04 \
  --build-arg PYTHON_VERSION=3 \
  --build-arg PAGEXML_VERSION=$PAGEXML_VERSION .
