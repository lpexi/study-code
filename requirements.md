# Programmieren 2 Klausur, Anforderungen

> Geteilte Basis aus der Vorbereitung. Die Themen unten sind aus den Vorlesungs-Abschnitten
> abgeleitet und teils durch konkrete Übungsschwerpunkte ergänzt. Sobald dir ein Klausurdetail
> einfällt, hier rein. Mit deinem Dozenten abgleichen.

## Bestätigte Themen

### Abschnitt 2: Von C zu C++
- Referenzen vs Pointer, dynamischer Speicher (new/delete), STL Container, Scope und Lifetime

### Abschnitt 3: OOP
- Klassendesign, Konstruktoren/Destruktoren, const correctness, this Pointer, Kapselung

### Abschnitt 4: UML und Vererbung
- Vererbungshierarchien, UML Klassendiagramme lesen und zeichnen, Konstruktor-Reihenfolge

### Abschnitt 5: Polymorphie
- virtuelle Funktionen, abstrakte Klassen, override, dynamisches Binden, vtable, Object Slicing

### Abschnitt 6: Generische Programmierung
- Funktions- und Klassentemplates, Template Parameter, Arbeit mit der STL
- Template-Spezialisierung einer generalisierten Klasse/Methode (Übungsschwerpunkt)
- Externe Methodendefinition bei Template-Klassen (Übungsschwerpunkt)

### Abschnitt 7: Exceptions und Smart Pointer
- Exception Handling (throw, try, catch), catch-Reihenfolge (abgeleitet vor Basis), Fangen per const Referenz
- Eigene Exception-Klassen (von std::runtime_error ableiten), allgemeiner catch(const std::exception&) als Fallback
- Exception Safety
- RAII-Prinzip (Ressource an Objektlebensdauer binden, Konstruktor erwirbt, Destruktor gibt frei)
- Smart Pointer: unique_ptr (exklusiver Besitz, make_unique, std::move zur Besitzübergabe, .get()),
  shared_ptr (geteilter Besitz, Referenzzähler, use_count), weak_ptr (kein Besitz, löst Zyklusproblem, lock)
- noexcept Keyword (Übungsschwerpunkt)
- Hintergrund Rule of Three: Destruktor mit delete[] zwingt zu Copy-Konstruktor + operator= oder = delete,
  sonst Double-Free bei flacher Kopie. Smart Pointer machen das großteils überflüssig.

### Abschnitt 8: Code Design
- Idiome und Best Practices, saubere Schnittstellen, Verantwortlichkeiten
- std::optional (Übungsschwerpunkt)
- Design Patterns: Factory Method Pattern, Observer Pattern, Adapter Pattern
  (Quelle: TSA-TSL25_Programmieren-II_Abschnitt-8_CodeDesign.pdf)

## Klärungen und Schwerpunkte
- (hier festhalten was der Dozent betont)

## Ausgeschlossen / niedrige Prio
- (hier festhalten was definitiv NICHT drankommt, sobald bekannt)

## Zuletzt aktualisiert
- Geteilte Baseline aus der gemeinsamen Vorbereitung. Mit deinem eigenen Stand und dem Dozenten abgleichen.
