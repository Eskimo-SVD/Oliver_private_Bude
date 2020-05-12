# Dies ist eine einfache Spec-Datei für ein einfaches Testprojekt
Summary: Ein Testprojekt zum packen einer eigenen RPM
Name: mein_projekt
Version: 0.1
Release: 1
Copyright: GPL
Group: misc/mein_projekt
Source: ftp://ftp.pronix.de/mein_projekt/ mein_projekt-0.1.tbz2
URL: http://pronix.de/mein_projekt/
Distribution: SuSE Linux 9.0
Vendor: Pronix Industries
Packager: Juergen Wolf <pronix@pronix.de>

%description
Bei diesem Paket handelt es sich um eine simples Beispiel
um Ihnen das erstellen eigener RPM-Paket naeher zu Erlaeutern.

%prep
%setup

%build
make

%install
cp "$RPM_BUILD_DIR"/mein_projekt-0.1/mein_projekt /usr/bin

%files
/usr/bin/mein_projekt








