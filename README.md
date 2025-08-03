# QMK Userspace

This is a [QMK Userspace](https://github.com/qmk/qmk_userspace) for custom keyboards layouts.

## Use

Install qmk

```shell
brew install qmk/qmk/qmk
```

Clone this repo and the `qmk_firmware` repo.
Remember to set up

```shell
qmk config user.qmk_home="$(realpath qmk_firmware)"
qmk config user.overlay_dir="$(realpath qmk_userspace)"
```

