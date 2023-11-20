unix: {

target.path = $${PREFIX}/bin
INSTALLS += target

unix_man.path = $${PREFIX}/share/man/man1
unix_man.files = ../debian/aphototoollibre.1.gz
INSTALLS += unix_man

unix_desktop.path = $${PREFIX}/share/applications
unix_desktop.files = ../desktop/aphototoollibre.desktop
INSTALLS += unix_desktop

unix_icons.path = $${PREFIX}/share/icons/hicolor/scalable/apps
unix_icons.files = ../desktop/aphototoollibre.svg
INSTALLS += unix_icons

unix_metainfo.path = $${PREFIX}/share/metainfo
unix_metainfo.files = ../desktop/aphototoollibre.metainfo.xml
INSTALLS += unix_metainfo

}