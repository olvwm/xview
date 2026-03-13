{ pkgs ? import <nixpkgs> {} }:
pkgs.mkShell {
  buildInputs = [
    pkgs.imake
    pkgs.libX11
    pkgs.xorg-cf-files
    pkgs.libXt
    pkgs.libXext
    pkgs.libXpm
    pkgs.bison
    pkgs.flex
  ];
}
