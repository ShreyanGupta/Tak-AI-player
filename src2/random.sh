#!/bin/bash

# ttab "python ../Tak-sim/server.py 1702 -n 7 -TL 360"
# ttab "python ../Tak-sim/client.py 127.0.0.1 1702 run.sh -n 7"
# ttab "python ../Tak-sim/client.py 127.0.0.1 1702 -mode none run1.sh -n 7"

# ttab "python ../Tak-sim/server.py 1702 -n 6 -TL 180"
# ttab "python ../Tak-sim/client.py 127.0.0.1 1702 run.sh -n 6"
# ttab "python ../Tak-sim/client.py 127.0.0.1 1702 -mode none run1.sh -n 6"

ttab "python ../Tak-sim/server.py 1702 -TL 30"
ttab "python ../Tak-sim/client.py 127.0.0.1 1702 run.sh"
ttab "python ../Tak-sim/client.py 127.0.0.1 1702 -mode none run1.sh"