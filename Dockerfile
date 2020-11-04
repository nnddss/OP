FROM gcc:10
WORKDIR /app/
COPY ./* ./
RUN g++ lexical.cpp -o lexical
RUN chmod +x lexical