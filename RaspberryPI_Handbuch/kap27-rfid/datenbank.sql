CREATE TABLE IF NOT EXISTS `user` (
  `id`        int(11) NOT NULL AUTO_INCREMENT,
  `name`      varchar(45) CHARACTER SET utf8 DEFAULT NULL,
```

\newpage

```sql
  `rfid`      text CHARACTER SET utf8,
  `timestamp` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00'
              ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`)
)