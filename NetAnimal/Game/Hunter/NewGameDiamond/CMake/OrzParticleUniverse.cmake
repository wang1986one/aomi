ORZ_FIND(OrzParticleUniverse OrzParticleUniverse bin/debug/ParticleUniverse_d.dll)
LINK_DIRECTORIES(${OrzParticleUniverse_LIBRARY_DIR})
INCLUDE_DIRECTORIES(${OrzParticleUniverse_INCLUDE_DIR} ${OrzParticleUniverse_INCLUDE_DIR}/ParticleUniverse )


INSTALL(FILES 
${OrzParticleUniverse_BIN_DIR}/debug/plugins.cfg
${OrzParticleUniverse_BIN_DIR}/debug/ParticleUniverse_d.dll
${OrzParticleUniverse_BIN_DIR}/debug/PUComponent.dll
DESTINATION ./bin/debug CONFIGURATIONS Debug)



INSTALL(FILES 
${OrzParticleUniverse_BIN_DIR}/release/plugins.cfg
${OrzParticleUniverse_BIN_DIR}/release/ParticleUniverse.dll
${OrzParticleUniverse_BIN_DIR}/release/PUComponent.dll
DESTINATION ./bin/release CONFIGURATIONS Release)



