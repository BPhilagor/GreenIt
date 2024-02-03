FROM ubuntu:latest
USER root
RUN apt-get update && \
    apt-get install -y apt-transport-https && \
    apt-get install -y python3-pip python3-dev && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*
RUN pip3 install Flask
CMD ["python3","-u","/etc/var/process_monitor.py"]