.PHONY: all up down clean vclean setup-dirs

all: setup-dirs up

setup-dirs:
	@mkdir -p /home/jahlee/data/db-data
	@mkdir -p /home/jahlee/data/wp-files

up:
	@echo "컨테이너 시작"
	@docker compose -f srcs/docker-compose.yml up -d

down:
	@echo "컨테이너 종료"
	@docker compose -f srcs/docker-compose.yml down

clean: down
	@echo "미사용 도커 리소스 정리"
	@docker system prune -af

vclean:
	@sudo rm -rf /home/jahlee/data
	@docker volume rm srcs_db-volume
	@docker volume rm srcs_wp-volume