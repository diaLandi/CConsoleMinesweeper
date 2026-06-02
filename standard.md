# MINESWEEPER

## Array

### Generelle Informationen

1 2D Feld

### Abspeicherungen

intern wird abgespeichert:
| char (als int) | Feld selbst | Umfeld (Wortwitz) | Status |
| :--- | :--- | :--- | :--- |
| `0` | leeres Feld  | keine Bomben |unentdeckt | 
| `1` | leeres Feld | eine Bombe | unentdeckt | 
| ... | leeres Feld | 2 - 7 Bomben | unentdeckt | 
| `8` | leeres Feld | 8 Bomben | unentdeckt | 
| `9` | Bombe | irrelewant | unentdeckt |
| `10` | Flagge | keine Bomben |unentdeckt | 
| `11` | Flagge | eine Bombe | unentdeckt | 
| ...  | Flagge | 2 - 7 Bomben | unentdeckt | 
| `18` | Flagge | 8 Bomben | unentdeckt | 
| `19` | Flagge & Bombe | irrelewant | unentdeckt |
| `'0'` | leeres Feld  | keine Bomben |entdeckt | 
| `'1'` | leeres Feld | eine Bombe | entdeckt | 
| ... | leeres Feld | 2 - 7 Bomben | entdeckt | 
| `'8'` | leeres Feld | 8 Bomben | entdeckt | 
| `'9'` | Bombe | irrelewant | entdeckt |

### Codes for the status variable

Variable: <br> `status`
| int - Wert | Bedeutung |
| :--- | :--- |
| `0` | im Spiel |
| `1` | verloren |
| `2` | gewonnen |

## Links für Live Share Extension

davor: https://prod.liveshare.vsengsaas.visualstudio.com/join?3CEF82B4C24613B650073107BA2C122EA507

19.05.2026 12:45: https://prod.liveshare.vsengsaas.visualstudio.com/join?4F706B20942A15E7A88422C2D786D41842B0

01.06.2026 10:07: https://prod.liveshare.vsengsaas.visualstudio.com/join?554A311DC512F6797E46648CC1627C0381A8

01.06.2026 14:13 https://prod.liveshare.vsengsaas.visualstudio.com/join?8FC96C35F8C423FDD3523408DB3D62583C80

02.06.2026 9:53 https://prod.liveshare.vsengsaas.visualstudio.com/join?9DD419FCDF3FD4867F1E9DBA7255BCABF77C