#!/usr/bin/env bash
set -e

PAGEXML_VERSION=2019.10.10

docker build \
  -f Dockerfile_runtime \
  -t mauvilsa/pagexml:runtime-ubuntu16.04-py35 \
  --build-arg UBUNTU_TAG=16.04 \
  --build-arg PAGEXML_VERSION=$PAGEXML_VERSION \
  .

docker build \
  -f Dockerfile_runtime \
  -t mauvilsa/pagexml:runtime-ubuntu18.04-py36 \
  --build-arg UBUNTU_TAG=18.04 \
  --build-arg PAGEXML_VERSION=$PAGEXML_VERSION \
  .

docker build \
  -f Dockerfile_runtime \
  -t mauvilsa/pagexml:runtime-ubuntu20.04-py37 \
  --build-arg UBUNTU_TAG=20.04 \
  --build-arg PAGEXML_VERSION=$PAGEXML_VERSION \
  .
