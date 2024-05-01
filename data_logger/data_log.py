from MQTT2Excel import MQTT2Excel

m2e = MQTT2Excel("127.0.0.1","data_log.xls")

#Set total row number you want to store in Excle
m2e.setRecordsNumber(1000)

# If you have more topics you just need to add another line with the name of the topic
m2e.addTopics("v1/devices/me/telemetry")
# m2e.addTopics("SBMS001/Voltage")
# m2e.addTopics("SBMS001/Percent")
# m2e.addTopics("SBMS001/Temp")
# m2e.addTopics("SBMS001/Hum")


m2e.start()
