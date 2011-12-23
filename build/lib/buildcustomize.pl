#!perl

# We are miniperl, building extensions
# Reset @INC completely, adding the directories we need, and removing the
# installed directories (which we don't need to read, and may confuse us)
@INC = (q /rig-build/build/cpan/AutoLoader/lib ,
        q /rig-build/build/dist/Cwd ,
        q /rig-build/build/dist/Cwd/lib ,
        q /rig-build/build/dist/ExtUtils-Command/lib ,
        q /rig-build/build/dist/ExtUtils-Install/lib ,
        q /rig-build/build/cpan/ExtUtils-MakeMaker/lib ,
        q /rig-build/build/dist/ExtUtils-Manifest/lib ,
        q /rig-build/build/cpan/File-Path/lib ,
        q /rig-build/build/ext/re ,
        q /rig-build/build/lib ,
        q . );
