Sieci - Semestr II
====

Basic Router and Switch Configuration
=====================================

#### CTRL-SHIFT-6 twoim przyjacielem TAB i '?' nie gryzą :\>

#### Nazwa urządzenia

``` {.bash language="bash"}
    R1(config)# hostname <name>
```

#### Wyłączenie irytujących rzeczy

``` {.bash language="bash"}
    R1(config)# no ip domain-lookup
    R1(config)# line con 0
    Switch(config-line)# logging synchronous 
```

#### Konfiguracja interfejsu

``` {.bash language="bash"}
    R1(config)# interface <int-nr>
    R1(config-if)# ip address <addr> <mask>
    R1(config-if)# no shutdown
```

#### Usuwanie adresu interfejsu

``` {.bash language="bash"}
    R1(config-if)# no ip address 
```

#### Ustawianie Clock Rate

``` {.bash language="bash"}
    R1(config-if)# clock rate 128000
```

#### wybór kilku portów

``` {.bash language="bash"}
    Switch(config)# int range f0/1 - 24, g0/1 - 2
```

#### Podstawowa diagnostyka

``` {.bash language="bash"}
    R1# show ip interface brief
```

#### Czyszczenie switcha - dla routera bez vlan

``` {.bash language="bash"}
    S1# delete vlan.dat
    S1# erase startup-config 
    S1# reload
```

Static Routing
==============

#### Wyświetlenie tablicy routingu

``` {.bash language="bash"}
    R1# show ip route
```

#### Routing statyczny

``` {.bash language="bash"}
    R1(config)# ip route <addr-sieci> <maska> <addr-na-ktory wysylac>
```

#### Routing statyczny - na port

``` {.bash language="bash"}
    R2(config)#ip route <addr-sieci> <maska> <port-na-ktory-wysylac>
```

#### Routing domyślny

Nie wiesz co zrobić z tym pakietem to wyślij go tam

``` {.bash language="bash"}
    R1(config)# ip route 0.0.0.0 0.0.0.0 <port-lub-addr> <opcjonalnie-dystans-administracyjny>
```

RIPv2
=====

#### Podstawowe ustawienia

``` {.bash language="bash"}
    R2(config)# router rip
    R2(config-router)# version 2
    R2(config-router)# no auto-summary 
    R2(config-router)# network <jakie sieci znam>
    R2(config-router)# network <jw>
    R2(config-router)# network <jw>
```

#### Propagacja tablic routingu

``` {.bash language="bash"}
    R1(config-router)# default-information originate 
```

#### Diagnostyka

``` {.bash language="bash"}
    R1# show ip route
    R1# show ip protocols
```

Basic Switch Security
=====================

#### Hasło

``` {.bash language="bash"}
    S1(config)# service password-encryption 
    S1(config)# enable secret class
```

#### Adres dla switcha

``` {.bash language="bash"}
    Switch(config)# ip default-gateway 172.17.99.1
    Switch(config)# end
```

#### Show VLAN

``` {.bash language="bash"}
    Switch# show vlan brief
```

#### Ustawienia hasła dostępu do konsoli

``` {.bash language="bash"}
    Switch(config)# line console 0
    Switch(config-line)# password cisco
    Switch(config-line)# login
    Switch(config-line)# logging synchronous 
    Switch(config-line)# exit
```

#### Telnet

``` {.bash language="bash"}
    Switch(config)# line vty 0 15
    Switch(config-line)# password cisco
    Switch(config-line)# login
    Switch(config-line)# end
```

#### Pokazanie tablicy maców

``` {.bash language="bash"}
    Switch# show mac address-table
```

SSH
===

#### Sprawdzenia czy da się postawić SSH

``` {.bash language="bash"}
    S1# show ip ssh
```

#### Konfiguracja domeny i klucza RSA

``` {.bash language="bash"}
    S1(config)# ip domain-name cisco.com
    S1(config)# crypto key generate rsa
```

#### Aktywacja dostępu przez SSH

``` {.bash language="bash"}
    S1(config)# username admin secret ccna
    S1(config)# line vty 0 15
    S1(config-line)# transport input ssh
    S1(config-line)# login local
    S1(config-line)# exit
    S1(config)# ip ssh version 2
```

VLAN
====

#### Tworzenie VLAN-a

``` {.bash language="bash"}
    S1(config)# vlan <nr>
    S1(config-vlan)# name <nazwa>
    S1(config-vlan)# exit
```

#### Przydzielenie portu do vlan-u

``` {.bash language="bash"}
    S1(config)# interface <int-nr>
    S1(config-if)# switchport mode access
    S1(config-if)# switchport access vlan <vlan-nr>
    S1(config-line)# end
```

Port Security
=============

#### Enable port security

``` {.bash language="bash"}
    S1(config-if)# switchport port-security
```

#### Configure static entry for the MAC address

``` {.bash language="bash"}
    S1(config-if)# switchport port-security mac-address xxxx.xxxx.xxxx 
```

#### Assign MAC address dynamic

``` {.bash language="bash"}
    S1(config-if)# switchport port-security mac-address sticky
```

#### Show port security

``` {.bash language="bash"}
    S1# show port-security interface f0/5
```

#### Restart port

``` {.bash language="bash"}
    S1(config-if)# shutdown
    S1(config-if)# no shutdown
```

VLAN - Trunk
============

#### Ustawienia portu w tryb trunk

``` {.bash language="bash"}
    S1(config)# interface range g0/1 -2
    S1(config-if-range)# switchport mode trunk 
```

#### Ustalenie jakie VLAN ma przepuszczać trunk

``` {.bash language="bash"}
    S1(config-if-range)# switchport trunk allowed vlan <vlan-list>
```

#### Diagnostyka

``` {.bash language="bash"}
    S1# show vlan brief
    S1# show interfaces trunk 
```

#### Zmiana enkapsulacji na dot1q - jakby normalnie nie działało

``` {.bash language="bash"}
    S1(config-if)# switchport trunk encapsulation dot1q
```

#### Router na kiju (lub jak kto woli Router-on-the-stick) 

INFO: bez tego shutdown na końcu nie zadziała

``` {.bash language="bash"}
    S1(config)# interface g0/1
    S1(config-if)# switchport mode trunk 
    
    R1(config-if)# int g0/0.<vlan-nr>
    R1(config-subif)# encapsulation dot1Q <vlan-nr>
    R1(config-subif)# ip address <ip-addr> <maska>
    
    R1(config-subif)# int g0/0
    R1(config-if)# no shutdown 
```

Access Control Lists
====================

#### Tworzenie ACL

``` {.bash language="bash"}
    R3(config)# access-list 1 remark Allow R1 LANs Access 
    R3(config)# access-list 1 permit 192.168.1 0.0 0.0.0.255 
    R3(config)# access-list 1 permit 192.168.2 0.0 0.0.0.255 
    R3(config)# access-list 1 deny any 
```

#### Przypisanie ACL do interfejsu

``` {.bash language="bash"}
    R3(config)# interface g0/1 
    R3(config-if)# ip access-group 1 out 
```

#### Diagnostyka

``` {.bash language="bash"}
    R3# show access-list
```

#### Nazwana ACL

``` {.bash language="bash"}
    R1(config)# ip access-list standard BRANCH-OFFICE-POLICY
    R1(config-std-nacl)# permit host 192.168.30.3
    R1(config-std-nacl)# permit 192.168.40.0 0.0.0.255 
```

#### Przypisanie nazwanej ACL do interfejsu

``` {.bash language="bash"}
    R1(config)# interface g0/1 
    R1(config-if)# ip access-group BRANCH-OFFICE-POLICY out
```

#### Configuring an IPv4 ACL on VTY Lines

``` {.bash language="bash"}
    Router(config)# access-list 99 permit host 10.0.0.1
    Router(config)# line vty 0 15
    Router(config-line)# access-class 99 in
```

DHCP
====

#### Wyłączenie adresów z puli

``` {.bash language="bash"}
    R2(config)# ip dhcp excluded-address <addr-start> <addr-stop>
```

#### Konfiguracja puli

``` {.bash language="bash"}
    R2(config)# ip dhcp pool <nazwa>
    R2(dhcp-config)# network <addr-network> <maska>
    R2(dhcp-config)# default-router <addr-ip-gateway>
    R2(dhcp-config)# dns-server <addr>
    R2(dhcp-config)# exit 
```

#### IP Helper Address 

Ustawiamy na interfejsie, na którym normalnie stoi brama domyślna.\
Adres helper to adres portu urządzenia połączonego bezpośrednio z naszym
routerem, na którym stoi DHCP

``` {.bash language="bash"}
    R1(config)# interface <int-name>
    R1(config-if)# ip helper-address <ip-addr>
```

#### Verification

``` {.bash language="bash"}
    R1# show ip dhcp binding
    R1# show ip dhcp pool
```

NAT
===

Static NAT
----------

#### Statyczne ustawienie tłumaczenia adresów

``` {.bash language="bash"}
    R1(config)# ip nat inside source static <inside_addr> <outside_addr>
```

#### Ustawienie interfejsu wewnętrznego

``` {.bash language="bash"}
    R1(config)# int <interface>
    R1(config-if)# ip nat inside
```

#### Ustawienie interfejsu zewnętrznego

``` {.bash language="bash"}
    R1(config)# int <interface>
    R1(config-if)# ip nat outside
```

Dynamic NAT
-----------

#### Ustawianie puli adresów dla NAT-a

``` {.bash language="bash"}
    R1(config)# ip nat pool <pool_name> <range-addr-start> <range-addr-end> netmask <mask>
```

#### Tworzenie ACL akceptującej tylko adresy do translacji

``` {.bash language="bash"}
    R1(config)# access-list 1 permit <net-addr> <negate-mask>
```

#### Związanie ACL z pulą adresów

``` {.bash language="bash"}
    R1(config)# ip nat inside source list <acl-list-number> pool <name>
```

#### Ustawienie interfejsu wewnętrznego

``` {.bash language="bash"}
    R1(config)# int <interface>
    R1(config-if)# ip nat inside
```

#### Ustawienie interfejsu zewnętrznego

``` {.bash language="bash"}
    R1(config)# int <interface>
    R1(config-if)# ip nat outside
```

PAT
---

#### Ustawianie puli adresów dla PAT-a

``` {.bash language="bash"}
    R1(config)# ip nat pool <pool_name> <range-addr-start> <range-addr-end> netmask <mask>
```

#### Tworzenie ACL akceptującej tylko adresy do translacji

``` {.bash language="bash"}
    R1(config)# access-list 1 permit <net-addr> <negate-mask>
```

#### Związanie ACL z konkretnym portem -\> nie tworzymy wtedy puli

``` {.bash language="bash"}
    R1(config)# ip nat inside source list <acl-list-number> interface <int-name> overload
```

#### Związanie ACL z pulą adresów

``` {.bash language="bash"}
    R1(config)# ip nat inside source list <acl-list-number> pool <name> overload
```

#### Ustawienie interfejsu wewnętrznego

``` {.bash language="bash"}
    R1(config)# int <interface>
    R1(config-if)# ip nat inside
```

#### Ustawienie interfejsu zewnętrznego

``` {.bash language="bash"}
    R1(config)# int <interface>
    R1(config-if)# ip nat outside
```

Verifying NAT
-------------

``` {.bash language="bash"}
    R1(config)# show ip nat translations
    R1(config)# show ip nat statistics
```
