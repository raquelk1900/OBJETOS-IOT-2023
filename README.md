# OBJETOS-IOT-2023
 Monitoramento inteligente da temperatura de aquários: aplicação em piscicultura.

link do projeto no WOKWI: https://wokwi.com/projects/365744349520069633

Projeto de construção de um sistema inteligente de monitoramento da temperatura da água, tendo como objetivo auxiliar o controle da temperatura e no futuro a obtenção de dados estatísticos para um cultivo mais produtivo na piscicultura ou aquários. 
A plataforma adotada para a simulação deste projeto será a Wokwi. Nela será simulado o atuador do projeto ESP32 e o sensor DS18B20, a comunicação com a internet foi feita via protocolo MQTT. 

Neste projeto a comunicação MQTT será feita desta forma: o Broker que fara o gerenciamento de mensagens será o test.mosquitto.org, o cliente será o mqtt-wokwi, a publicação será feita pelo Módulo ESP32 + sensor DS18B20 e o assinante será o software MQTT Explorer. 
