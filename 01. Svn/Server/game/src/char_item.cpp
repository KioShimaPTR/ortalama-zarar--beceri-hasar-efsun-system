//Coded Bahadýr Bozdað || Cosby || Kioshima

//Search function:

									else if (item->GetVnum() == 76014)
									{
										int aiChangeProb[ITEM_ATTRIBUTE_MAX_LEVEL] = 
										{
											0, 10, 50, 39, 1
										};

										item2->ChangeAttribute(aiChangeProb);
									}

//Add below:

									else if (item->GetVnum() == 71052)
									{
										if (item2->GetType() != ITEM_WEAPON)
										{
											ChatPacket(CHAT_TYPE_INFO, "Sadece silahlara efsun ekleyebilirsin.");
											return false;
										}

										if (item2->GetAttributeType(0) != 72)
										{
											ChatPacket(CHAT_TYPE_INFO, "Sadece ortalama zararý efsunu olan silahlara efsun ekleyebilirsin.");
											return false;
										}

										item2->ChangeAttribute();

										while (item2->GetAttributeType(0) != 72 || item2->GetAttributeType(1) != 71)
											item2->ChangeAttribute();

										int iNormalHitBonus = number(45,60);
										item2->SetForceAttribute(0, 72, iNormalHitBonus);

										int iSkillBonus = 0;
										if (iNormalHitBonus >= 45 && iNormalHitBonus <= 50)
											iSkillBonus = number(-20,-15);
										else
											iSkillBonus = iNormalHitBonus / -2 - 0.5f - number(-2,0);

										item2->SetForceAttribute(1, 71, iSkillBonus);
									}
									else if (item->GetVnum() == 71053)
									{
										if (item2->GetType() != ITEM_WEAPON)
										{
											ChatPacket(CHAT_TYPE_INFO, "Sadece silahlara efsun ekleyebilirsin.");
											return false;
										}

										if (item2->GetAttributeType(0) != 71 && item2->GetAttributeType(1) != 71)
										{
											ChatPacket(CHAT_TYPE_INFO, "Sadece beceri hasar efsunu olan silahlara efsun ekleyebilirsin.");
											return false;
										}

										item2->ChangeAttribute();

										while (item2->GetAttributeType(0) != 72 || item2->GetAttributeType(1) != 71)
											item2->ChangeAttribute();

										int iSkillBonus = number(18,28);

										for (int x = 0; x < ITEM_ATTRIBUTE_MAX_NUM; x++)
										{
											if (item2->GetAttributeType(x) == 71)
												item2->SetForceAttribute(x, 71, iSkillBonus);
										}

										int iNormalHitBonus = 0;
										if (iSkillBonus <= 20)
											iNormalHitBonus = -2 * iSkillBonus + abs(number(-8, 8) + number(-8, 8)) + number(1, 4);
										else
											iNormalHitBonus = -2 * iSkillBonus + number(1, 5);

										item2->SetForceAttribute(0, 72, iNormalHitBonus);
									}