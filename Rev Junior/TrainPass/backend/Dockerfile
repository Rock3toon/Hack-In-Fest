FROM debian:trixie-slim

WORKDIR /ctf

RUN apt-get update && apt-get install -y socat gcc && rm -rf /var/lib/apt/lists/*

COPY . .

RUN gcc -o Train_Pass Train_Pass.c
RUN chmod +x Train_Pass
RUN chmod 444 flag.txt

RUN useradd -m ctf && chown -R ctf:ctf /home/ctf

USER ctf

EXPOSE 1002

CMD ["sh", "-c", "socat -d -d -T 120 TCP4-LISTEN:1002,fork,reuseaddr EXEC:'./Train_Pass',pty,ctty,setsid,raw,echo=0,stderr"]
