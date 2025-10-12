# QMK Userspace

This is a [QMK Userspace](https://github.com/qmk/qmk_userspace) for custom keyboards layouts.
It's meant to be used together with the [`us_cat`](https://github.com/schildwaechter/us_cat) layout.

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

## Compile

```shell
make avalanche/v4:schildwaechter
make avalanche/v4:schildwaechter:flash
```

or

```shell
make keebio/iris_lm/k1:schildwaechter
make keebio/iris_lm/k1:schildwaechter:flash
```
