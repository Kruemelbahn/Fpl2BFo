# Fpl2BFo

is a Windows program for reading FPL-files (created from [FPLEdit](https://fahrplan.manuelhu.de/)) and convert the file into a BFO-file (BFO = Station timetable) which can contain more than the timetable from FPL-file.
The program is compiled for x64-mode and works under Windows 10 or 11 and may work also on previous Windows-Versions (without guarantee). A version for Windows-32 is also available.<br>

There is no setup necessary, please copy all file into a (new) directory and enjoy.<br>

The program was created to the best of our knowledge and without guarantee of function in the hope that it will be useful.
If it is not useful - then it is not.
A translation of the software into other languages is not planned.

# Fpl2BFo (de)

ist ein Windows-Programm zum Lesen von FPL-Dateien (erstellt aus [FPLEdit](https://fahrplan.manuelhu.de/)) und zum Konvertieren der Datei in eine BFO-Datei (BFO = [Bahnhofsfahrordnung](https://de.wikipedia.org/wiki/Fahrplan_f%C3%BCr_Zugmeldestellen)), die mehr als den Fahrplan aus einer FPL-Datei enthalten kann.
Das Programm ist für den x64-Modus kompiliert und funktioniert unter Windows 10 oder 11 und möglicherweise auch auf früheren Windows-Versionen (ohne Gewähr). Eine Version für Windows-32 ist ebenfalls verfügbar.<br>

Es ist keine Installation erforderlich, einfach alle Dateien in ein (neues) Verzeichnis kopieren und das Programm starten.<br>

Das Programm wurde nach bestem Wissen und ohne Gewähr auf Funktion erstellt in der Hoffnung, dass es einen Nutzen bringt.
Wenn es nicht nützlich ist, dann eben nicht.
Eine Übersetzung der Software in andere Sprachen ist nicht vorgesehen.

## neu in Version 1.1
- mehrere Fehler beseitigt
- Ausgabe der Startaufstellung als Aufsteller oder Karten

## neu in Version 1.2
- einige kleine Fehler behoben
- Ausgabe der Beschreibung zur Handhabung der BFO-Datei
- Eigene Symboldefinitionen möglich 

## neu in Version 2.0
- schweren Fehler beim Lesen/Schreiben der BFO-Datei behoben
- Unterstützung von Hexadezimalwerten für die Verwendung bei Farben für benutzerdefinierte Symbole 

## neu in Version 2.1
- schweren Fehler beim Lesen der FPL-Datei behoben
- beim Starten des Programms hilft jetzt ein Startassistent
- Bahnhofsfahrordnung kann jetzt ohne Fahrplandatei erstellt werden
- weitere kleine Fehler behoben

## neu in Version 2.2
- Plausibilitätsprüfung der Daten
- Zusammenfassen einiger Ausgabedialoge
- Aufteilung der Settings auf mehrere Seiten
- Dateiendungen können jetzt registriert werden, wenn das Programm als Administrator gestartet wird
- Fehlerprüfung der BFO vor einer Seitenansicht, dem Drucken bzw. dem Speichern
- Ein- und Ausgabe von Dokumententitel, aktueller Bahnhofsname und Fahrplaninformationen zur BFO
- Dropdownliste für 'Gleis' bei der Bearbeitung einer Zeile in der Startaufstellung
- HTML-Export: Bahnhofsbild kann base64-codiert ausgegeben werden
- neues Addon "Suchen und Ersetzen"
- weitere kleine Fehler behoben
 
## neu in Version 2.3
- weitere kleine Fehler behoben

## neu in Version 2.4
- kleine Fehler u.a. für CustomChar bei der HTML-Ausgabe behoben
- neue Funktionen in der Bahnhofsauswahl und der Startaufstellung
- neue Plausibilitätsprüfungen
- Hilfe aktualisiert

## neu in Version 2.4.1
- Korrektur nach der Lizenzierung

## neu in Version 2.5
- verbesserte Unterstützung bei den Prüfläufen, Hilfe aktualisiert
- Registrierung der Dateiendungen für die Dateivorschau korrigiert und erweitert

## neu in Version 3.0
- neue Funktionen, Erweiterungen von Funktionen, Korrekturen (siehe [Release-Notes](https://github.com/Kruemelbahn/Fpl2BFo/blob/main/ReleaseNotes.txt))
- Hilfe aktualisiert

## neu in Version 3.0.1
- Korrekturen (siehe [Release-Notes](https://github.com/Kruemelbahn/Fpl2BFo/blob/main/ReleaseNotes.txt))

## neu in Version 3.1
- neue Funktionen, Erweiterungen von Funktionen, Korrekturen (siehe [Release-Notes](https://github.com/Kruemelbahn/Fpl2BFo/blob/main/ReleaseNotes.txt))
- Hilfe aktualisiert

> [!NOTE]
> Wenn das Programm „Fpl2BFo.exe“ nicht gestartet werden kann, weil MFC140.DLL fehlt,
> verwenden Sie bitte „vc_redist.xxx.exe“, ein Installationsprogramm für MFC140.DLL, das hier heruntergeladen werden kann (originaler Link zur Microsoft-Seite):
> 
> - für Win32: https://aka.ms/vs/17/release/vc_redist.x86.exe 
> - für Win64: https://aka.ms/vs/17/release/vc_redist.x64.exe
> 
> Führen Sie die heruntergeladene Datei zur Installation aus.
