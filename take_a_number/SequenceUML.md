
```mermaid
sequenceDiagram
    participant Clerk
    participant QueueMS
    participant CustomerN
    CustomerN->>QueueMS: Request Queue number
    Clerk->>QueueMS: Request Next Number in Line
    Clerk->>CustomerN: Deliver Package
```
