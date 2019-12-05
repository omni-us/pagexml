
#docker build \
#  -f Dockerfile_build \
#  -t mauvilsa/pagexml:build-ubuntu16.04-py27 \
#  --build-arg UBUNTU_TAG=16.04 \
#  --build-arg PYTHON_VERSION=2 \
#  .

docker build \
  -f Dockerfile_build \
  -t mauvilsa/pagexml:build-ubuntu16.04-py35 \
  --build-arg UBUNTU_TAG=16.04 \
  --build-arg PYTHON_VERSION=3 \
  .

docker build \
  -f Dockerfile_build \
  -t mauvilsa/pagexml:build-ubuntu18.04-py36 \
  --build-arg UBUNTU_TAG=18.04 \
  --build-arg PYTHON_VERSION=3 \
  .

#cd ../../
##docker build -f py-pagexml/docker/Dockerfile_test -t mauvilsa/pagexml:test-ubuntu16.04-py27 --build-arg BUILD_TAG=build-ubuntu16.04-py27 . &&
#docker build -f py-pagexml/docker/Dockerfile_test -t mauvilsa/pagexml:test-ubuntu16.04-py35 --build-arg BUILD_TAG=build-ubuntu16.04-py35 . &&
#docker build -f py-pagexml/docker/Dockerfile_test -t mauvilsa/pagexml:test-ubuntu18.04-py36 --build-arg BUILD_TAG=build-ubuntu18.04-py36 .
