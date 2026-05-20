# Vollständige ANSI-SGR-Code-Referenz (0m - 107m)

Diese Übersicht enthält alle standardisierten SGR-Parameter (Select Graphic Rendition) des ANSI-Escape-Standards. 

## Struktur & Kombination
* **Syntax:** `\033[Stil;Vordergrund;Hintergrundm[Dein Text]\033[0m`
* **Mehrfach-Kombination:** Du kannst beliebig viele Codes mit einem Semikolon `;` trennen.
* **Beispiel (C):** `printf("\033[1;4;5;31;103mBlinkender Text\033[0m");` 
  *(Fett, unterstrichen, langsam blinkend, roter Text auf hellgelbem Hintergrund)*

---

## 1. Alle Steuerzeichen / Text-Stile (0m - 29m)

Diese Gruppe steuert das grundlegende Schriftbild sowie das gezielte Zurücksetzen einzelner Eigenschaften. Die Unterstützung für Blinken, Fraktur oder alternative Schriftarten hängt stark vom verwendeten Terminal-Emulator ab.

| Code | Effekt | Beschreibung / Terminal-Verhalten |
| :--- | :--- | :--- |
| **0m** | **Reset / Normal** | Setzt absolut alle Stile und Farben auf den Standardwert zurück. |
| **1m** | Fett / Erhöhte Intensität | Macht Text fett (und auf älteren Systemen farblich heller). |
| **2m** | Dim / Verringerte Intensität | Macht den Text blasser/dunkler (Gegenteil von fett). |
| **3m** | Kursiv (Italic) | Schräge Schrift (wird von fast allen modernen Terminals unterstützt). |
| **4m** | Unterstrichen | Zieht eine einfache Linie unter den Text. |
| **5m** | Blinkend (langsam) | Text blinkt (unter 150 Mal pro Minute). |
| **6m** | Blinkend (schnell) | Schnelles Blinken (wird von modernen Terminals meist ignoriert). |
| **7m** | Invertiert (Reverse video) | Tauscht die Vordergrund- und Hintergrundfarbe. |
| **8m** | Verborgen (Conceal) | Macht Text unsichtbar (wird oft für Passworteingaben genutzt). |
| **9m** | Durchgestrichen | Zieht eine Linie horizontal durch den Text. |
| **10m** | Standard-Schriftart | Schaltet auf die primäre Schriftart des Terminals zurück. |
| **11m - 19m** | Alternative Schriftarten | Schaltet auf alternative Zeichensätze/Schriftarten um. |
| **20m** | Fraktur (Blackletter) | Schaltet auf Frakturschrift (extrem selten unterstützt). |
| **21m** | Doppelt unterstrichen | Zieht zwei Linien unter den Text (manchmal stattdessen "Fett aus"). |
| **22m** | Intensität normal | Schaltet Fett (`1m`) und Dim (`2m`) wieder aus. |
| **23m** | Kursiv aus | Schaltet Kursivschrift (`3m`) wieder aus. |
| **24m** | Unterstreichung aus | Schaltet einfache/doppelte Unterstreichung aus. |
| **25m** | Blinken aus | Schaltet das Blinken (`5m` & `6m`) wieder aus. |
| **26m** | Proportionale Schrift | Schaltet auf proportionale Schriftart um (falls unterstützt). |
| **27m** | Invertierung aus | Schaltet den invertierten Modus (`7m`) aus. |
| **28m** | Sichtbar machen | Schaltet den verborgenen Modus (`8m`) wieder aus. |
| **29m** | Durchgestrichen aus | Schaltet die Durchstreichung (`9m`) wieder aus. |

---

## 2. Standard-Vordergrundfarben (30m - 39m)

Standard-Farbpalette für den eigentlichen Text.

| Code | Farbe / Effekt | Beschreibung |
| :--- | :--- | :--- |
| **30m** | Schwarz | |
| **31m** | Rot | |
| **32m** | Grün | |
| **33m** | Gelb | |
| **34m** | Blau | |
| **35m** | Magenta | |
| **36m** | Cyan | |
| **37m** | Weiß / Hellgrau | |
| **38m** | Erweiterte Farben | Wird für 8-Bit (256 Farben) oder 24-Bit (Truecolor RGB) genutzt. <br> *Syntax 256 Farben:* `38;5;[0-255]m` <br> *Syntax RGB:* `38;2;[R];[G];[B]m` |
| **39m** | Standard-Textfarbe | Setzt ausschließlich die Textfarbe auf den Terminal-Standard zurück. |

---

## 3. Standard-Hintergrundfarben (40m - 49m)

Standard-Farbpalette für den Hintergrund hinter dem Text.

| Code | Hintergrundfarbe / Effekt | Beschreibung |
| :--- | :--- | :--- |
| **40m** | Schwarzer Hintergrund | |
| **41m** | Roter Hintergrund | |
| **42m** | Grüner Hintergrund | |
| **43m** | Gelber Hintergrund | |
| **44m** | Blauer Hintergrund | |
| **45m** | Magenta Hintergrund | |
| **46m** | Cyan Hintergrund | |
| **47m** | Weißer / Hellgrauer Hintergrund | |
| **48m** | Erweiterter Hintergrund | Wird für erweiterte Hintergrundpaletten genutzt. <br> *Syntax 256 Farben:* `48;5;[0-255]m` <br> *Syntax RGB:* `48;2;[R];[G];[B]m` |
| **49m** | Standard-Hintergrund | Setzt ausschließlich den Hintergrund auf den Terminal-Standard zurück. |

---

## 4. Sonder- und Formatierungs-Resets (50m - 65m)

Diese Codes stammen aus erweiterten Spezifikationen (z. B. für Textrahmen oder spezielle ostasiatische Zeichensatz-Effekte). Sie funktionieren nur auf ausgewählten xterm-kompatiblen Emulatoren.

| Code | Effekt | Beschreibung |
| :--- | :--- | :--- |
| **50m** | Proportionale Schrift aus | Deaktiviert den Proportionalmodus (`26m`). |
| **51m** | Gerahmt (Framed) | Zeichnet einen rechteckigen Rahmen um den Text. |
| **52m** | Umkreist (Encircled) | Zeichnet einen Kreis/Ellipse um den Text. |
| **53m** | Überstrichen (Overlined) | Zieht eine Linie über den Text (Gegenteil von Unterstreichen). |
| **54m** | Rahmen / Umkreisung aus | Schaltet die Modi `51m` und `52m` wieder aus. |
| **55m** | Überstreichung aus | Deaktiviert die Linie über dem Text (`53m`). |
| **56m - 59m** | *Nicht definiert* | Für zukünftige Standardisierungen reserviert. |
| **60m** | Ideogramm unterstrichen | Rechtsbündige oder einfache Unterstreichung für Ideogramme. |
| **61m** | Ideogramm doppelt unterstrichen | Doppelte Unterstreichung für Ideogramme. |
| **62m** | Ideogramm überstrichen | Einfache Überstreichung für Ideogramme. |
| **63m** | Ideogramm doppelt überstrichen | Doppelte Überstreichung für Ideogramme. |
| **64m** | Ideogramm Stress-Markierung | Setzt Betonungsmarker über oder neben die Zeichen. |
| **65m** | Ideogramm Attribute aus | Setzt alle spezifischen Ideogramm-Stile (60m-64m) zurück. |

---

## 5. Helle Textfarben / High Intensity (90m - 97m)

Diese Farben besitzen von Natur aus eine höhere Leuchtkraft und Sättigung als die Standard-30er-Gruppe.

| Code | Farbe |
| :--- | :--- |
| **90m** | Helles Schwarz / Dunkelgrau |
| **91m** | Helles Rot |
| **92m** | Helles Grün |
| **93m** | Helles Gelb |
| **94m** | Helles Blau |
| **95m** | Helles Magenta |
| **96m** | Helles Cyan |
| **97m** | Helles Weiß |

*(Hinweis: Die Codes **98m** und **99m** existieren im offiziellen Standard nicht).*

---

## 6. Helle Hintergrundfarben / High Intensity (100m - 107m)

Leuchtende, hochintensive Hintergrundfarben analog zu den Textfarben.

| Code | Hintergrundfarbe |
| :--- | :--- |
| **100m** | Dunkelgrauer Hintergrund |
| **101m** | Hellroter Hintergrund |
| **102m** | Hellgrüner Hintergrund |
| **103m** | Hellgelber Hintergrund |
| **104m** | Hellblauer Hintergrund |
| **105m** | Hellmagenta Hintergrund |
| **106m** | Hellcyan Hintergrund |
| **107m** | Hellweißer Hintergrund |