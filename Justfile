[private]
default:
    just --list --justfile {{ justfile() }}

format:
    indent src/*.c src/*.h -linux -nut -i4

release:
    flatpak-builder --user --install --force-clean build/release build-aux/com.konstantintutsch.Caffeine.yaml 

devel:
    flatpak-builder --user --install --force-clean build/devel build-aux/com.konstantintutsch.Caffeine.Devel.yaml 

test:
    flatpak-builder --user --install --force-clean --disable-download build/devel build-aux/com.konstantintutsch.Caffeine.Devel.yaml
    GTK_DEBUG=interactive flatpak run com.konstantintutsch.Caffeine.Devel

setup:
    sudo dnf install -y indent
    sudo dnf install -y meson
    sudo dnf install -y flatpak-builder
    sudo dnf install -y libadwaita-devel
    flatpak install --user --assumeyes org.gnome.Sdk//47 org.gnome.Platform//47
