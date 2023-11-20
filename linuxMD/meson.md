meson --prefix=${PREFIX} --libdir=lib/${TRIPLEF} ..
echo user-PC: x:1000:0:user-PC:/usr > /etc/passwd
meson build --prefix=${PREFIX}
ninja -C build
sudo ninja -C build install

