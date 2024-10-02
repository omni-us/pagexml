#!/usr/bin/env bash
set -e

docker build \
  -f Dockerfile_build \
  -t mauvilsa/pagexml:build-ubuntu20.04-py38 \
  --build-arg UBUNTU_TAG=20.04 \
  .

docker build \
  -f Dockerfile_build \
  -t mauvilsa/pagexml:build-ubuntu22.04-py310 \
  --build-arg UBUNTU_TAG=22.04 \
  .

docker build \
  -f Dockerfile_build \
  -t mauvilsa/pagexml:build-ubuntu24.04-py312 \
  --build-arg UBUNTU_TAG=24.04 \
  .
