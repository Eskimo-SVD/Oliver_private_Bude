#!/usr/bin/python
from dbupload import DropboxConnection
conn = DropboxConnection("michael.kofler@gmx.com", "2P236HWgz")
fname = 'temperaturen.txt'
conn.upload_file(fname, "/", fname)
