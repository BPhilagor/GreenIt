DOCKER_NAME = greenIT
COMPOSE_FILE = docker-compose/docker-compose.yml
CONTAINERS = $(shell docker ps -a -q)
TIDY=2>/dev/null ; true

up :
	docker-compose -f $(COMPOSE_FILE) -p $(DOCKER_NAME) up --build

down:
	docker-compose -f $(COMPOSE_FILE) -p $(DOCKER_NAME) down

fclean :
	docker volume rm  $(shell docker volume ls -q)   $(TIDY)

clean:
	docker stop       $(CONTAINERS)                  $(TIDY)
	docker rm         $(CONTAINERS)                  $(TIDY)
	docker network rm $(shell docker network ls -q)  $(TIDY)
	docker image rm   $(shell docker image ls -q)    $(TIDY)

re : clean up


CN = scaphandre prometheus process_monitor grafana

$(CN) :
	docker exec -it $@ /bin/bash

.PHONY: up fclean re $(CN) down
