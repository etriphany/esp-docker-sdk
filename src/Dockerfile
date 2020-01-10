FROM        alpine:3.5

LABEL       maintainer             "etriphany.com"

# Alpine packages
ENV         PACKAGES               "make python"
ENV         TMP_PACKAGES           "py-pip"

# SDK Requirements
ENV         GLIBC_VER               "2.25-r0"
ENV         GLIBC_PACKAGES_URI      "https://github.com/sgerrand/alpine-pkg-glibc/releases/download/${GLIBC_VER}"
ENV         GLIBC_PACKAGES          "glibc-${GLIBC_VER}.apk glibc-bin-${GLIBC_VER}.apk"

# SDK Components
ENV         ESP_TOOL               "esptool"
ENV         ESP_SDK_URI            "https://github.com/espressif/ESP8266_NONOS_SDK/archive/v3.0.1.tar.gz"
ENV         XTENSA_TOOLCHAIN       "xtensa_tc.tar.xz"


#
# Container Setup
# (adapted from official https://docs.espressif.com/projects/esp8266-rtos-sdk/en/latest/get-started/linux-setup.html)
# --------------------------
#
# NOTE: Alpine uses "musl" which is not compatible with xtensa toolchain, that binds to "glibc".
#       To solve it we use https://github.com/sgerrand/alpine-pkg-glibc
#

ENV         PATH                   "${PATH}:/home/user/esp-open-sdk/xtensa-lx106-elf/bin"

# Fixing wget SSL URIs
RUN         apk update --no-cache && \
            apk add ca-certificates && \
            update-ca-certificates && \
            apk add wget

# Install Alpine packages
RUN         wget -q -O  /etc/apk/keys/sgerrand.rsa.pub https://alpine-pkgs.sgerrand.com/sgerrand.rsa.pub && \
            wget ${GLIBC_PACKAGES_URI}/glibc-${GLIBC_VER}.apk && \
            wget ${GLIBC_PACKAGES_URI}/glibc-bin-${GLIBC_VER}.apk && \
            apk add ${PACKAGES} ${TMP_PACKAGES} ${GLIBC_PACKAGES} && \
            pip install ${ESP_TOOL} --upgrade pip && \
            apk del ${TMP_PACKAGES} --purge && \
            rm -rf ${GLIBC_PACKAGES} /var/cache/apk/

#
# User setup
# --------------------------
#
# NOTE: User must access USB devices, but not valuable
#       since docker-compose requires root for bind volumes
# --
RUN         adduser -S -G dialout user
USER        user


#
# Espressif SDK + Xtensa Toolchain
# --------------------------
#
# NOTE: Xtensa toolchain on Alpine is tricky, kept a valid version as full binary
#       better if could download a reliable version somewhere
#
WORKDIR     /home/user/
# Binary toolchain
COPY        /contents/xtensa .
# Espressif SDK / Extract / Set owner
RUN         wget -q -O esp_sdk.tar.gz ${ESP_SDK_URI} && \
            tar -xf esp_sdk.tar.gz && \
            tar -xf ${XTENSA_TOOLCHAIN} && \
            rm esp_sdk.tar.gz ${XTENSA_TOOLCHAIN} && \
            chown -R user /home/user/
# Sample
COPY        /contents/example/blink-led ./blink-led

#
# Run
# --------------------------
CMD         ["/bin/sh"]