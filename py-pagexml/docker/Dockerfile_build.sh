#!/usr/bin/env bash
set -e

docker build \
  -f Dockerfile_build \
  -t mauvilsa/pagexml:build-ubuntu16.04-py35 \
  --build-arg UBUNTU_TAG=16.04 \
  .

docker build \
  -f Dockerfile_build \
  -t mauvilsa/pagexml:build-ubuntu18.04-py36 \
  --build-arg UBUNTU_TAG=18.04 \
  .

docker build \
  -f Dockerfile_build \
  -t mauvilsa/pagexml:build-ubuntu20.04-py38 \
  --build-arg UBUNTU_TAG=20.04 \
  .
