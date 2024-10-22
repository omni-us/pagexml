#!/usr/bin/env bash
set -e

PAGEXML_VERSION=2022.04.12

docker build \
  -f Dockerfile_runtime \
  -t mauvilsa/pagexml:runtime-ubuntu20.04-py38 \
  --build-arg UBUNTU_TAG=20.04 \
  --build-arg PAGEXML_VERSION=$PAGEXML_VERSION \
  .

docker build \
  -f Dockerfile_runtime \
  -t mauvilsa/pagexml:runtime-ubuntu22.04-py310 \
  --build-arg UBUNTU_TAG=22.04 \
  --build-arg PAGEXML_VERSION=$PAGEXML_VERSION \
  .

docker build \
  -f Dockerfile_runtime \
  -t mauvilsa/pagexml:runtime-ubuntu24.04-py312 \
  --build-arg UBUNTU_TAG=24.04 \
  --build-arg PAGEXML_VERSION=$PAGEXML_VERSION \
  .
