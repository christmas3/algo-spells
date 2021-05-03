FROM ubuntu:latest 

RUN apt-get -y update && \
    apt-get install -y && \
    apt-get install -y cmake g++

ADD . /src/spells

WORKDIR /src/spells/build

RUN cmake .. && \
    cmake --build .
