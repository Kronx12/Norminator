import os
import sys
import getpass
import platform
from datetime import datetime

def c_date(path_to_file):
    if platform.system() == 'Windows':
        return os.path.getctime(path_to_file)
    else:
        stat = os.stat(path_to_file)
        try:
            return stat.st_birthtime
        except AttributeError:
            return stat.st_mtime

def get_header(name, i):
	creation_date = str(datetime.utcfromtimestamp(int(c_date(name))).strftime('%Y/%m/%d %H:%M:%S'))
	modification_date = str(datetime.utcfromtimestamp(int(os.path.getmtime(name))).strftime('%Y/%m/%d %H:%M:%S'))
	basename = sys.argv[i].split("/")[len(sys.argv[i].split("/")) - 1]
	login = getpass.getuser()
	header = []
	header.append("/* " + "*" * 74 + " */")
	header.append("/* " + " " * 74 + " */")
	header.append("/* " + " " * (74 - 19) + ":::      ::::::::   */")
	header.append("/*   " + basename + " " * (74 - 23 - len(basename)) + ":+:      :+:    :+:   */")
	header.append("/*                                                    +:+ +:+         +:+     */")
	header.append("/*   By: " + login + " <" + login + "@student.42lyon.fr>" + " " * (44 - 22 - 2 * len(login)) + "+#+  +:+       +#+        */")
	header.append("/*                                                +#+#+#+#+#+   +#+           */")
	header.append("/*   Created: " + creation_date + " by " + login + (19 - len(login) - 1) * " " + "#+#    #+#             */")
	header.append("/*   Updated: " + modification_date +" by " + login + (18 - len(login) - 1) * " " + "###   ########lyon.fr   */")
	header.append("/* " + " " * 74 + " */")
	header.append("/* " + "*" * 74 + " */")
	header.append("")
	return header