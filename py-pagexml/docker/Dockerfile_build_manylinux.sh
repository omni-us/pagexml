#!/usr/bin/env bash

WD=$(cd .. && pwd)
IMAGE=quay.io/pypa/manylinux_2_28_x86_64:latest
PY=313

docker run \
  --rm \
  -t \
  --env HOME=/tmp \
  --user $(id -u):$(id -g) \
  --workdir "$WD" \
  --volume $HOME:$HOME \
  --entrypoint bash \
  $IMAGE \
  -c "
    set -e
    /opt/python/cp$PY-cp$PY/bin/pip install setuptools pkgconfig
    /opt/python/cp$PY-cp$PY/bin/python setup.py bdist_wheel --slim
    auditwheel repair dist/pagexml_slim-*-cp$PY-cp$PY-linux_x86_64.whl
    /opt/python/cp$PY-cp$PY/bin/pip install wheelhouse/pagexml_slim-*-cp$PY-cp$PY-manylinux*.whl
    /opt/python/cp$PY-cp$PY/bin/python -m pagexml_tests
  "
