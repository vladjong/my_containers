FROM alpine

WORKDIR /project/

COPY . .

RUN apk add ; apk add gcc g++ gtest gtest-dev make valgrind bash

ENTRYPOINT [ "/bin/bash" ]
