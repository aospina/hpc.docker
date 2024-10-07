# Instalación de cluster MPI y OpenMP con docker

## Instalar docker en linux-ami2 (m4.xlarge)

    sudo amazon-linux-extras install docker -y
    sudo yum install git -y

    sudo systemctl enable docker
    sudo systemctl start docker
    sudo usermod -a -G docker ec2-user

## Instalar docker-compose: https://docs.docker.com/compose/install/

    sudo curl -L https://github.com/docker/compose/releases/download/1.29.2/docker-compose-`uname -s`-`uname -m` -o /usr/local/bin/docker-compose
 
    sudo chmod +x /usr/local/bin/docker-compose

    exit

## Iniciando a instalar el Cluster MPI con docker:

Usaremos [Docker Compose](https://docs.docker.com/compose/) para definir y ejecutar múltiples contenedores. 
 
## Crear el archivo `docker-compose.yml`
 
   ```
version: '2.4'

services:
  mpi_head:
    build: .
    ports:
      - "2222:22"
    volumes:
      - ./compartido:/compartido
    depends_on:
      - mpi_node

  mpi_node:
    build: .
    volumes:
      - ./compartido:/compartido

   ```
Note que este archivo esta disponible en este git para su descarga.
 
## Construir el cluster:

Para un cluster con 3 nodos (`mpi_head` y 3 `mpi_node`) será:

    docker-compose up --scale mpi_node=3

Una vez que esto haya terminado de ejecutarse, puedes ver con `docker ps -a` que tienes 4 contenedores docker ejecutándose.  Puede obtener las direcciones IP de todas estas máquinas usando

    docker inspect -f '{{range .NetworkSettings.Networks}}{{.IPAddress}}{{end}}' NAME

donde NAME es `hpcdocker_mpi_node_[1-3]` y `hpcdocker_mpi_head_1` para los 3 nodos y el master (server/head).  Estás ip's servirán para el archivo de host para ejecutar MPI

Ahora podemos realizar SSH al head del cluster:

```
chmod 400 ssh/id_rsa.mpi
ssh -i ssh/id_rsa.mpi  mpirun@MPI_HEAD_IP
```

Tenga en cuenta que si quieres cambiar tu código y recompilar que debes trabajar en la carpeta /compartido y con el usuario *mpirun*.  De lo contrario tendrá que copiar el binario a todos los nodos remotos:  MPI no transmite el binario, asume que que existe en todas las máquinas remotas.  

## Todo listo
¡Diviértete! con tu cluster MPI con docker. 

## Créditos
Gracias al trabajo de https://github.com/dispel4py/ by O. Weidner y R. Filgueira
