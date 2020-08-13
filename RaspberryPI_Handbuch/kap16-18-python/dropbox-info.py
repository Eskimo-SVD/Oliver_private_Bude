#!/usr/bin/python3
import dropbox
db = dropbox.Dropbox('your-token')
print('Account infos: ', db.users_get_current_account())
