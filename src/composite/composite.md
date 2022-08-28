# The Composite Pattern

## The `Gang of Four` Definition

## Use Case

## UML Diagrams
```plantuml
@startuml composite_1
    actor Customer
    Customer -> "login()" : username & password
    "login()" -> Customer : session token
    activate "login()"
    Customer -> "placeOrder()" : session token, order info
    "placeOrder()" -> Customer : ok
    Customer -> "logout()"
    "logout()" -> Customer : ok
    deactivate "login()"
@enduml
```

![](composite_1.svg)