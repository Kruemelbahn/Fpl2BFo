### Schnittstelle zu Fpl2BFoDat

Fpl2BFo bietet über Fpl2BFoDat.DLL eine Entwicklerschnittstelle an.

Diese Schnittstelle kann genutzt werden, um die Daten aus einer FPL-, BFO-, BFOTEMPL- und/oder STA-Datei zu lesen.
Die gelesenen Daten stehen einem Entwickler als Rohdaten (d.h. ohne weitere Interpretation oder Verarbeitung) zur Verfügung.
Unterstützt werden hierbei alle aktuell bekannten Dateiformate der oben genannten Dateitypen.
Die Schnittstelle ist unidirektional: Daten können nur gelesen und nicht geschrieben werden. 

**Hinweis:** 
1. die Entwicklerschnittstelle _muss_ über eine erweiterte Lizenz freigeschaltet werden.
2. Für diese Schnittstelle steht mit Fpl2BFOServer ein COM-Server zur Verfügung, der über einen entsprechenden Client verwendet werden kann.
   _Nicht vergessen_: ein COM-Server muss unter Windows registriert werden, um benutzt werden zu können, z.B. mit 'regsvr32 "dllname with fullpath"'
3. Pfadangaben in den Dateien sind immer auf die eigene Entwicklungsumgebung anzupassen.
