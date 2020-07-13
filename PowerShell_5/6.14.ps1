# Klartextnamen für MemoryType
$memorytype = 'Unknown', 'Other', 'DRAM', 'Synchronous DRAM', 'Cache DRAM', 'EDO', 'EDRAM', 'VRAM', 'SRAM', 'RAM', 'ROM', 'Flash', 'EEPROM', 'FEPROM', 'EPROM', 'CDRAM', '3DRAM', 'SDRAM', 'SGRAM', 'RDRAM', 'DDR', 'DDR-2', 'DDR2 FB-DIMM', 'DDR3', 'FBD2'

# Klartextnamen für FormFactor
$formfactor = 'Unknown', 'Other', 'SIP', 'DIP', 'ZIP', 'SOJ', 'Proprietary', 'SIMM', 'DIMM', 'TSOP', 'PGA', 'RIMM', 'SODIMM', 'SRIMM', 'SMD', 'SSMP', 'QFP', 'TQFP', 'SOIC', 'LCC', 'PLCC', 'BGA', 'FPBGA', 'LGA'

# Berechnete Eigenschaften definieren:

# Capacity in Gigabyte umrechnen:
$spalte1 = @{Name='Größe (GB)'; Expression={ $_.Capacity/1GB } }

# FormFactor in Klartext umwandeln:
$spalte2 = @{Name='Bauart'; Expression={$formfactor[$_.FormFactor]} }

# MemoryType in Klartext umwandeln:
$spalte3 = @{Name='Speichertyp'; Expression={ $memorytype[$_.MemoryType] } }

Get-WmiObject Win32_PhysicalMemory | Select-Object PartNumber, $spalte1, $spalte2, $spalte3
