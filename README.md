
<h1 align="center">ESP Docker SDK</h1>
<p align="center">
    <img src="https://raw.githubusercontent.com/etriphany/esp-docker-sdk/master/docs/img/esp01.jpeg" height="225"/>
    <img src="https://raw.githubusercontent.com/etriphany/esp-docker-sdk/master/docs/img/docker.png" height="225"/>
</p>


# Description

Docker image for ESP8266 developers that includes:

* [Espressif NonOS SDK](https://www.espressif.com/en/products/hardware/esp8266ex/resources): Official ESP8266 SDK, non Real Time OS design
* [ESPTool](https://github.com/espressif/esptool): Serial tool for ESP8266
* [Xtensa Toolchain](https://github.com/noduino/xtensa-toolchain): Cross compiler for [Tesilica Architecture](https://tensilicatools.com/platform/espressif-esp8266/) based on GCC


# Requirements

* [Docker](www.docker.com)
* [Docker Compose](https://docs.docker.com/compose/)


# Using it

The container uses a `bind mount` that points to the folder `project`.
So to access any project inside the container, just create a symbolic link to this folder:

```sh
  $ ln -s /path/to/your/project project
```

Now you can

#### Start the container
```sh
  $ docker-compose up -d
```

#### Access the container

```sh
$ docker-compose exec espsdk /bin/sh
```

#### Stop the container
```sh
$ CTRL+D
$ docker-compose stop
```


# Tips

1- Look the **blink-led** example to see how setup your project

2- If you use `push-button` programmer circuits, be sure to adjust `esptool.py` calls in your `Makefile`, including the option **--before no_reset**.

Example:

 ```sh
 $ esptool.py --chip esp8266 --before no_reset {YOUR COMMAND}
 ```

> Now after executing a Make command, simply do the manual reset (by pushing Flash/Reset) and everything will work like a charm!